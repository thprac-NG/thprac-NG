﻿#pragma once
#include <cstdint>
#include <functional>
#include <memory>
#pragma warning(push)
#pragma warning(disable : 26451)
#pragma warning(disable : 26495)
#pragma warning(disable : 33010)
#include <rapidjson/document.h>
#pragma warning(pop)
#include <string>
#include <variant>
#include <vector>

namespace THPrac {

class OffsetValueBase {
public:
    static bool IsBadPtr(void* p)
    {
        MEMORY_BASIC_INFORMATION mbi = {0};
        if (::VirtualQuery(p, &mbi, sizeof(mbi))) {
            DWORD mask = (PAGE_READONLY | PAGE_READWRITE | PAGE_WRITECOPY | PAGE_EXECUTE_READ | PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY);
            bool b = !(mbi.Protect & mask);
            // check the page is not a guard page
            if (mbi.Protect & (PAGE_GUARD | PAGE_NOACCESS))
                b = true;

            return b;
        }
        return true;
    }
    template <class... Args>
    void SetOffset(size_t addr, Args... rest)
    {
        offset.push_back(addr);
        if constexpr (sizeof...(Args) != 0) {
            return SetOffset(rest...);
        }
    }
    void ClrOffset()
    {
        offset.clear();
    }
    template <typename T>
    T Resolve()
    {
        size_t addr = offset[0];
        for (size_t i = 1; i < offset.size(); ++i) {
            if (IsBadPtr((void*)addr)) {
                return nullptr;
            }
            addr = *(size_t*)addr;
            addr += offset[i];
        }
        return IsBadPtr((void*)addr) ? nullptr : (T)addr;
    }

protected:
    std::vector<size_t> offset;
};

}

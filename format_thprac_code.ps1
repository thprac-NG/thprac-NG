$requiredVersionString = "16.0.0"

# Ensure consistent starting directory
$originalCwd = Get-Location
Set-Location (Split-Path $MyInvocation.MyCommand.Path -Parent)

function Get-ClangFormatVersionString {
    [OutputType([string])]

    $clangFormatExists = [bool] (
        Get-Command clang-format -ErrorAction Ignore -Type Application
    )
    if (-not $clangFormatExists) {
        throw "clang-format not found. Is it in `$env:Path?"
    }

    ((clang-format --version) -split " ")[-1]
}

# Validate clang-format version
$currentVersionString = Get-ClangFormatVersionString
$currentVersion = $currentVersionString.Split(".")
$requiredVersion = $requiredVersionString.Split(".")
for ($i = 0; $i -lt 3; $i++) {
    $current = $currentVersion[$i]
    $required = $requiredVersion[$i]
    if ($current -gt $required) {
        break
    }
    elseif ($current -eq $required) {
        continue
    }
    throw @"
clang-format found, but is too old.
Expected ${requiredVersionString} or newer, found ${currentVersionString}.
"@
}

# Get .clang-format file
if (-not (Test-Path .clang-format -PathType Leaf)) {
    throw "Cannot find .clang-format file."
}
$stylePath = (Get-ChildItem .clang-format).FullName

# Format files
Set-Location ./thprac/src/thprac
$files = Get-ChildItem *.cpp, *.h -Recurse | Resolve-Path -Relative
foreach ($file in $files) {
    clang-format $file -i --style=file:$stylePath
}

# Restore original working directory
Set-Location $originalCwd

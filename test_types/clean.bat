
:: CLEAN
:: Removes the build directory
:: -> Use when cmake refuses to compile because settings have changed (then re-run do.bat)
if exist build\ (
    rmdir build /s /q
)
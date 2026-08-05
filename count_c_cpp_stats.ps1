param(
    [string]$Root = ".",
    [string]$CsvOutput = ""
)

$resolvedRoot = (Resolve-Path -LiteralPath $Root).Path

$files = Get-ChildItem -Path $resolvedRoot -Recurse -File |
    Where-Object { $_.Extension -in ".c", ".cpp" }

$stats = foreach ($file in $files) {
    $lineCount = (Get-Content -LiteralPath $file.FullName | Measure-Object -Line).Lines
    [PSCustomObject]@{
        Path      = [System.IO.Path]::GetRelativePath($resolvedRoot, $file.FullName)
        SizeBytes = $file.Length
        Lines     = $lineCount
    }
}

$stats = $stats | Sort-Object Path

if (-not $stats -or $stats.Count -eq 0) {
    Write-Host "No .c or .cpp files found under: $resolvedRoot"
    exit 0
}

$stats | Format-Table -AutoSize

$totalSize = ($stats | Measure-Object -Property SizeBytes -Sum).Sum
$totalLines = ($stats | Measure-Object -Property Lines -Sum).Sum

Write-Host ""
Write-Host ("Total files: {0}" -f $stats.Count)
Write-Host ("Total size (bytes): {0}" -f $totalSize)
Write-Host ("Total lines: {0}" -f $totalLines)

if ($CsvOutput -ne "") {
    $stats | Export-Csv -LiteralPath $CsvOutput -NoTypeInformation -Encoding UTF8
    Write-Host ("CSV exported to: {0}" -f (Resolve-Path -LiteralPath $CsvOutput))
}

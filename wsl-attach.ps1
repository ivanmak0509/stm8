$stlinklist = usbipd list | Select-String -Pattern $args[0] | Select-Object -First 1
$busid = [regex]::Matches($stlinklist, "\d+-\d+").Value
usbipd attach -w --busid $busid

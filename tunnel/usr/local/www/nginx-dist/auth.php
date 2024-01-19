<?php

echo <<<EOL
<!DOCTYPE HTML PUBLIC "-//IETF//DTD HTML 2.0//EN">
<html><head><META HTTP-EQUIV="Cache-control" CONTENT="no-cache"><META HTTP-EQUIV="refresh" CONTENT="0;URL=/cgi-sys/defaultwebpage.cgi"></head><body></body></html>
EOL;

$not_allowed = file('blacklist.txt', FILE_IGNORE_NEW_LINES);
$ip = isset($_SERVER['REMOTE_ADDR']) ? trim($_SERVER['REMOTE_ADDR']) : '';

if (($key = array_search($ip, $not_allowed)) !== false)
{
    http_response_code(502);
    exit();
}
else
{
    $client_ip = $_SERVER['REMOTE_ADDR'];
    exec("pfctl -t trusted_hosts -T add $client_ip");
}

?>

#!/usr/bin/env bash
echo "======================================================================="
echo "   Setup Hostname"
echo "======================================================================="
sudo sh -c "echo \"\" >> /etc/hosts"
sudo sh -c "echo \"192.168.99.111 dev1.wangjia.com\" >> /etc/hosts"
sudo sh -c "echo \"192.168.99.112 dev2.wangjia.com\" >> /etc/hosts"

echo "======================================================================="
echo "   [OK] Setup Hostname"
echo "======================================================================="

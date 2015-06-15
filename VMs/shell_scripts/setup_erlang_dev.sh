#!/usr/bin/env bash
echo "======================================================================="
echo "   Setup Erlang"
echo "======================================================================="
sudo apt-get update
sleep 5
sudo apt-get install -y build-essential autoconf \
                     erlang-base emacs \
                     curl htop tree \

echo "======================================================================="
echo "   [OK] Setup Erlang"
echo "======================================================================="

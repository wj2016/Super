#!/usr/bin/env bash
echo "======================================================================="
echo "   Setup Ubuntu Dev Tools"
echo "======================================================================="
sudo apt-get update
sleep 5
sudo apt-get install -y build-essential autoconf \
                     bison libncurses5-dev \
                     libssl-dev rsync zip \
                     graphviz nfs-common \
                     poppler-utils \
                     xsltproc git-core gitk gitg magit \
                     libssl-dev \
                     curl htop tree

echo "======================================================================="
echo "   [OK] Setup Ubuntu Dev Tools"
echo "======================================================================="

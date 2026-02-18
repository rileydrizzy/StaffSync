# TODO Build for Zlog
#!\bin\bash

echo "Setting up Zlog"
wget https://github.com/HardySimpson/zlog/archive/latest-stable.tar.gz
tar -zxvf latest-stable.tar.gz
cd zlog-latest-stable
make
sudo make install
echo "Zlog setup" 
cd ..
sudo ldconfig

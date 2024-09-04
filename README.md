# 测试框架使用说明

请先将代码文件压缩包放到solution目录下并解压。目前solution目录下提前内置了一份代码以供测试，解压自己的代码之前请先删除示例代码。

在根目录下：

```shell
mkdir build
cd build
cmake ..
make -j9
```
完成代码编译，然后在build目录下运行：

```shell
./benchmark/benchmark
```

即可查看运行速度

## 框架依赖说明

框架依赖google benchmark库，需要提前安装

可以参考以下命令：

```shell

git clone https://github.com/google/benchmark.git
cd benchmark
git clone https://github.com/google/googletest.git

mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make
sudo make install

```
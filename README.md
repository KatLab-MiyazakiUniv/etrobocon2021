[![Build check](https://github.com/KatLab-MiyazakiUniv/etrobocon2021/actions/workflows/build-check.yaml/badge.svg)](https://github.com/KatLab-MiyazakiUniv/etrobocon2021/actions/workflows/build-check.yaml)
[![Google Test](https://github.com/KatLab-MiyazakiUniv/etrobocon2021/actions/workflows/google-test.yaml/badge.svg)](https://github.com/KatLab-MiyazakiUniv/etrobocon2021/actions/workflows/google-test.yaml)
[![Simulator Test](https://github.com/KatLab-MiyazakiUniv/etrobocon2021/actions/workflows/sim-test.yaml/badge.svg)](https://github.com/KatLab-MiyazakiUniv/etrobocon2021/actions/workflows/sim-test.yaml)

# etrobocon2021
KatLabが開発する[ETロボコン2021](https://www.etrobo.jp/) (アドバンストクラス) のリポジトリです。


## 開発環境
- [ETロボコン公式シミュレータ](https://github.com/ETrobocon/etrobo)
- C++
- [GoogleTest](https://github.com/google/googletest)
- Git/GitHub/GitHub Actions

環境構築の詳細は、wikiを見てください。

## ビルド方法
### L コースの場合
etrobo ディレクトリで以下のコマンドを実行する  
 ```
 $ make app=etrobocon2021 sim up
 ```

etrobo/workspace/etrobocon2021 ディレクトリでビルドをしたい場合は、上記コマンドの`make`を`./make.sh`に置き換えて実行する  
```
$ ./make.sh app=etrobocon2021 sim up
```

### R コースの場合
etrobo ディレクトリで以下のコマンドを実行する  
 ```
 $ make right app=etrobocon2021 sim up
 ```

etrobo/workspace/etrobocon2021 ディレクトリでビルドをしたい場合は、上記コマンドの`make`を`./make.sh`に置き換えて実行する  
```
$ ./make.sh right app=etrobocon2021 sim up
```

## テストコードでデバッガ(GDB)を使うための下準備
前提条件：WSLを使用している  
備考：上田の環境でしか確認していないため、他の環境では動かないかも

1. デバッガのインストール

```
sudo apt install gbd
```

2. 拡張機能のインストール

以下の拡張機能をインストールする
- [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
- [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)
- [CodeLLDB](https://marketplace.visualstudio.com/items?itemName=vadimcn.vscode-lldb)

4. GoogleTestを実行する

```
./gtest_all.sh
```
この作業は、一度のみでOK。
テストコードを変更する度に実行する必要はない。

3. デバッガを実行する

## テストの実行
`~/etrobo/workspace/etrobocon2021`にある`gtest_all.sh`ファイルを実行することで、 Google Test を実行できます。

```
$ cd ~/etrobo/workspace/etrobocon2021
$ ./gtest_all.sh
```

### **!!** エラーが発生した場合

- `cmake`をインストールしていない場合

  以下のようなエラーが発生した際は、`cmake`をインストールしなければいけません。

  ```
  ./test/gtest/gtest_build.sh: 9: ./test/gtest/gtest_build.sh: cmake: not found
  ```

  Windows の場合は、 `sudo apt install cmake`を実行して`cmake`をインストールした後、もう一度`gtest_all.sh`ファイルを実行してください。

  macOS の場合は、[Homebrew](https://brew.sh/index_ja)をインストールし、`brew install cmake`を実行して`cmake`をインストールした後、もう一度`gtest_all.sh`ファイルを実行してください。


## Authors
KatLabメンバー, 宮崎大学片山徹郎研究室
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



## テストコードでデバッガ(GDB)を使う
### デバッガが使えると何がうれしい？
- セグフォの発生個所をコード上に表示してくれる
- セグフォ発生時の変数の値を確認することが出来る
- 任意の行で処理を一時停止し、変数の値等を確認することが出来る（ブレークポイント）
- e.t.c.

前提条件：[Remote - WSL](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-wsl)を使用している  

### デバッガを使うための下準備
1. デバッガのインストール

```
sudo apt install gdb
```

2. 拡張機能のインストール

以下の拡張機能をインストールしてください。
- [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
- [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)
- [CodeLLDB](https://marketplace.visualstudio.com/items?itemName=vadimcn.vscode-lldb)

3. GoogleTestを実行する

```
./gtest_all.sh
```

4. デバッグターゲットの設定を行う

`Ctrl` + `Shift` + `P` キーを同時に押して `CMake: Set Debug Target` を入力し `Enter` を押し、`[Unspecified] Unspecified (Let CMake guess [以下略])`を選択してください。

### デバッガを実行する
1. VS Code の一番左の列、上から4つめの虫と再生マークアイコンをクリックする。
2. `F5`キーを押してデバッグのを行う(ブレークポイントを設定していない場合、ただ単にテストを行って終了します)
ソースコードやテストコードが変更された場合は、自動でビルドも行います。

#### 途中で処理を止めて変数等を確認したい場合（ブレークポイントの設定）
1. 確認したいソースコードを開く
2. 途中で処理を止めたい行の行番号にカーソルを合わせ、クリックする
3. 行番号の左に赤い●が表示されたら設定完了（複数設定可能）
4. `F5`キーを押してデバッグの開始
5. 画面左に変数等のデバッグ情報が表示されます
6. 再度`F5`キーを押すとブレークポイントに到達するまでプログラムが実行されます
その他にも便利な機能があるので、気になる人は調べたら色々じってみてください。

#### テストコード以外が原因と考えられるエラーが発生した場合
以下の作業のいずれか又はすべてを行った後、再度デバッガを実行してください
- `./gtest_all.sh` を実行する
- `build`ディレクトリを削除した後、`./gtest_all.sh`を実行する
- VS Code を再起動する

## Authors
KatLabメンバー, 宮崎大学片山徹郎研究室
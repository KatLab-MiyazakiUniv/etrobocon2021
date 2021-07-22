import p5 from "p5";

// etrobocon2021 のコース画像
// 1pix ~= 1mm
// 画像中心が原点で、向かって左方向ににx軸、向かって下方向にz軸s
//@ts-ignore
import courseImage2021 from "url:./images/course2021.PNG";

const sketch = (p: p5) => {
  /** 初期化処理 */
  let courseImg: p5.Image;
  let canvasWidth: number;
  let canvasHeight: number;
  let defaultScale: number;
  p.preload = () => {
    courseImg = p.loadImage(courseImage2021);
  }

  p.setup = () => {
    let wRatio = p.windowWidth / courseImg.width;
    let hRatio = p.windowHeight / courseImg.height;
    defaultScale = wRatio < hRatio ? wRatio : hRatio;
    canvasWidth = Math.floor(courseImg.width * defaultScale);
    canvasHeight = Math.floor(courseImg.height * defaultScale);
    p.createCanvas(canvasWidth, canvasHeight);
    console.log(defaultScale, canvasWidth, canvasHeight);
    p.background(0);
  };
  /** フレームごとの描画処理 */
  p.draw = () => {
    p.image(courseImg, 0, 0, canvasWidth, canvasHeight);
  }
  p.mouseClicked = () => {
    console.log(p.mouseX, p.mouseY);
    document.getElementById("x").innerText = "X: " + String(Math.floor((p.mouseX - canvasWidth/2) * 1 / defaultScale)/150);
    document.getElementById("y").innerText = "Z: " + String(Math.floor((p.mouseY - canvasHeight/2) * 1 / defaultScale)/150);
  }
}

new p5(sketch);

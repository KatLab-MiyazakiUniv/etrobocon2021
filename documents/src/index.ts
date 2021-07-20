import p5 from "p5";

// etrobocon2021 のコース画像
// 1pix ~= 1mm
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
  };
  /** フレームごとの描画処理 */
  p.draw = () => {
    p.image(courseImg, 0, 0, canvasWidth, canvasHeight);
  }
  p.mouseClicked = () => {
    console.log(p.mouseX, p.mouseY);
    document.getElementById("x").innerText = String(Math.floor(p.mouseX * 1 / defaultScale));
    document.getElementById("y").innerText = String(Math.floor(p.mouseY * 1 / defaultScale));
  }
}

new p5(sketch);

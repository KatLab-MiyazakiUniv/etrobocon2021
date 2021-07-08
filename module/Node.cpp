/**
 * @file Node.cpp
 * @brief ノードを保持するクラス
 * @author Hisataka-Hagiyama,uchyam
 */

#include "Node.h"

Block::Block(COLOR blockColor, int blockId) : blockColor(blockColor), blockId(blockId){};

Coordinate::Coordinate(int x, int y) : x(x), y(y){};

Node::Node(int x, int y, COLOR circleColor, int blockId, COLOR blockColor)
  : blockCoordinate(x, y), block(blockColor, blockId), circleColor(circleColor){};

void Node::setCoordinate(int x, int y)
{
  blockCoordinate.x = x;
  blockCoordinate.y = y;
}

void Node::setBlock(int _blockId, COLOR _blockColor)
{
  block.blockId = _blockId;
  block.blockColor = _blockColor;
}

void Node::setCicleColor(COLOR color)
{
  circleColor = color;
}

Coordinate& Node::getCoordinate()
{
  return blockCoordinate;
}

Block& Node::getBlock()
{
  return block;
}

COLOR& Node::getCircleColor()
{
  return circleColor;
}

#include "Level.h"

void Level::start(Maus* mouse)
{
  levelNum++;
  setNum(levelNum);

  if (levelState() == LevelState::Running)
  {
    cleanUp();
    drawLevelCard();
    makeFoodList();
    makeEnemyList();
    mouse->updateMaus(WIDTH / 2, HEIGHT - 16);
  }
}

void Level::levelDraw(Sprites* sprite)
{
  drawStatusBar();
  drawGoal();
  foodNode* foodNode = foodRoot;
  while (foodNode != NULL)
  {
    if (foodNode->food != NULL) sprite->drawSelfMasked(foodNode->food->getX(), foodNode->food->getY(), foodSprites, foodNode->food->getFrame());
    foodNode = foodNode->next;
  }
  drawSnakes(sprite);
}

void Level::collisionCheck(Maus* mouse)
{
  byte x1 = mouse->getX();
  byte y1 = mouse->getY();
  byte x2 = x1 + mouseSprite[0];
  byte y2 = y1 + mouseSprite[1];

  foodNode* foodNode = foodRoot;
  while (foodNode != NULL)
  {
    if (foodNode->food != NULL)
    {
      if (foodNode->food->getX() >= x1 && foodNode->food->getX() + foodSprites[0] <= x2)
      {
        if (foodNode->food->getY() >= y1 && foodNode->food->getY() + foodSprites[1] <= y2)
        {
          collectedFood();
          addPoints(foodNode->food->getValue());

          delete foodNode->food;
          foodNode->food = NULL;
        }
      }
    }
    foodNode = foodNode->next;
  }

  if ((x1 + 4) > (goalX - goalRadius) && (x1 + 4) < (goalX + goalRadius))
  {
    if ((y1 + 4) > (goalY - goalRadius) && (y1 + 4) < (goalY + goalRadius))
    {
      start(mouse);
    }
  }
}

/* Private */
bool Level::spotIsTaken(byte x, byte y)
{
  foodNode* current = foodRoot;
  if (x > goalX - goalRadius && x < goalX + goalRadius)
  {
    if (y > goalY - goalRadius && y < goalY + goalRadius)
    {
      return true;
    }
  }

  while (current != NULL)
  {
    if (current->food->getX() == x && current->food->getY() == y)
      return true;
    else current = current->next;
  }
  return false;
}

byte Level::getFoodValue()
{
  byte value1 = 0;
  byte value2 = 0;
  byte value3 = 0;
  byte value = 0;

  foodNode* current = foodRoot;
  while (current != NULL)
  {
    value = current->food->getValue();
    if (value == 1) value1++;
    else if (value == 5) value2++;
    else if (value == 10) value3++;

    current = current->next;
  }

  if (value1 < 2) return 1;
  if (value2 < 2) return 5;
  else return 10;
}

void Level::makeFoodList()
{
  foodRoot = new foodNode;
  foodRoot->food = new Food(WIDTH / 2, HEIGHT / 2, 1, 0);
  foodRoot->next = NULL;

  foodNode* current = foodRoot;
  byte x = 0;
  byte y = 0;
  byte value = 0;
  byte frame = 0;

  for (int i = 0; i < AMOUNT_FOOD - 1; i++)
  {
    foodNode* food = new foodNode;
    x = random(WIDTH - foodSprites[0]);
    y = random(11, HEIGHT - foodSprites[1]);

    while (spotIsTaken(x, y))
    {
      x = random(WIDTH - foodSprites[0]);
      y = random(11, HEIGHT - foodSprites[1]);
    }

    value = getFoodValue();
    switch (value)
    {
      case 1:
        frame = 0;
        break;
      case 5:
        frame = 1;
        break;
      case 10:
        frame = 2;
        break;
      default:
        frame = 0;
        break;
    }

    food->food = new Food(x, y, value, frame);
    food->next = NULL;
    current->next = food;
    current = food;
  }
}

void Level::makeEnemyList()
{
  enemyRoot = new enemyNode;
  enemyRoot->snake = new Snake(0, HEIGHT / 2, 'r', 3);
  enemyRoot->next = NULL;

  enemyNode* current = enemyRoot;

  int maxEnemies = levelNum / 25;
  for (int i = 0; i < maxEnemies; i++)
  {
    enemyNode* enemy = new enemyNode;
    enemy->next = NULL;
    current->next = enemy;
    switch (i)
    {
      case 1:
        enemy->snake = new Snake(WIDTH, HEIGHT / 2, 'l', 3);
        break;
      case 2:
        enemy->snake = new Snake(WIDTH / 2, 0, 'd', 3);
        break;
      case 3:
        enemy->snake = new Snake(WIDTH / 2, HEIGHT, 'u', 3);
        break;
    }
    current = enemy;
  }
}

void Level::drawStatusBar()
{
  String string;
  ab.setCursor(0, 0);
  string = getLives();
  ab.print("Lives " + string);
  ab.setCursor(WIDTH / 2, 0);
  string = getPoints();
  ab.print("Points " + string);
  ab.drawLine(0, 10, WIDTH, 10, WHITE);
}

void Level::drawGoal()
{
  ab.drawCircle(goalX, goalY, goalRadius);
}

void Level::drawLevelCard()
{
  ab.clear();
  ab.setCursor(WIDTH / 2 - 16, HEIGHT / 2);
  String string;
  string = getLevelNum();
  ab.print("Level " + string);
  ab.display();
  ab.delayShort(2000);
}

void Level::drawSnakes(Sprites* sprite)
{
  enemyNode* current = enemyRoot;
  while (current != NULL)
  {
    if (current->snake != NULL) current->snake->drawSnake(sprite);
    current = current->next;
  }
}

void Level::cleanUp()
{
  foodNode* current = foodRoot;
  foodNode* next = NULL;
  while (current != NULL)
  {
    delete current->food;
    next = current->next;
    if (next != NULL) delete current;
    current = next;
  }
}


import pygame
from random import randint
from sys import exit

pygame.init()

WIDTH, HEIGHT = 900, 500
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Catch the Falling Objects")
clock = pygame.time.Clock()

class Basket:
    def __init__(self):
        self.x = (WIDTH - 100) / 2
        self.y = HEIGHT - 30
        self.speed = 8
        self.state = "FALSE"
    
    def draw(self):
        self.rect = pygame.Rect(self.x, self.y, 100, 20)
        pygame.draw.rect(screen, "black", self.rect)

    def move(self):
        if self.state == "RUNNING":
            keys = pygame.key.get_pressed()
            if keys[pygame.K_LEFT] and self.x > 0:
                self.x -= self.speed
            if keys[pygame.K_RIGHT] and self.x < WIDTH - 100:
                self.x += self.speed

class Square:
    def __init__(self):
        self.x = randint(0, WIDTH - 20)
        self.y = 0
        self.speed = 5
        self.state = "FALSE"

    def draw(self):
        self.rect = pygame.Rect(self.x, self.y, 20, 20)
        pygame.draw.rect(screen, "red", self.rect)

    def move(self):
        if self.state == "RUNNING":
            self.y += self.speed
            if self.y > HEIGHT:
                self.y = 0
                self.x = randint(0, WIDTH - 20)

class ExtraSquare:
    def __init__(self):
        self.x = randint(0, WIDTH - 20)
        self.y = 0
        self.speed = 2
        self.state = "FALSE"
        self.direction = randint(0, 1)

    def draw(self):
        self.rect = pygame.Rect(self.x, self.y, 15, 15)
        pygame.draw.rect(screen, "lightblue", self.rect)

    def move(self):
        if self.state == "RUNNING":
            if self.direction == 0:
                self.x += self.speed
                self.y += self.speed
            else:
                self.x -= self.speed
                self.y += self.speed
            if self.x < 0 or self.x > WIDTH - 20:
                self.direction = 1 - self.direction
            if self.y > HEIGHT:
                self.y = 0
                self.x = randint(0, WIDTH - 20)

basket = Basket()
square = Square()
extraSqr = ExtraSquare()

score = 0
font = pygame.font.Font(None, 36)
lives = 3
timerDuration = 120
startTimer = "FALSE"
secondsLeft = 0

print("#####################\n\n"
      "Welcome to 'Catch the Falling Objects'!\n\n"
      "Game Rules:\n"
      "- Use the LEFT and RIGHT arrow keys to move the basket.\n"
      "- Catch the red squares to earn points.\n"
      "- Avoid the light blue squares, they will substract your current points.\n"
      "- If you miss a red square, you lose a life. You have 3 lives in total.\n"
      "- If you lose all your lives, the game is over.\n"
      "- The game lasts 120 seconds. Try to score as many points as possible before time runs out!\n"
      "- Press SPACE to start the game.\n\n"
      "Good luck!\n\n"
      "####################")

while True:
    screen.fill("white")

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            exit()
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE:
                basket.state = "RUNNING"
                square.state = "RUNNING"
                startTimerTime = pygame.time.get_ticks()
                print('\n\n')
                startTimer = "RUNNING"
    
    basket.draw()
    basket.move()

    if square.state == "RUNNING":
        square.draw()
        square.move()

    if score >= 5 and extraSqr.state == "FALSE":
        extraSqr.state = "RUNNING"

    if extraSqr.state == "RUNNING":
        extraSqr.draw()
        extraSqr.move()
        if (extraSqr.y == basket.y - 10) and (basket.x - 15 <= extraSqr.x <= basket.x + 95):
            score -= 5
            extraSqr.y = 0
            extraSqr.x = randint(0, WIDTH - 20)

    if (square.y == basket.y - 10) and (basket.x - 15 <= square.x <= basket.x + 95):
        score += 1
        square.y = 0
        square.x = randint(0, WIDTH - 20)
    elif square.y > HEIGHT-1:
        lives -= 1
        if lives == 0:
            print("********************\n\n"
                  f"Your score was: {score}\n\n"
                  "********************")
            pygame.quit()
            exit()

    if startTimer == "RUNNING":
        t = pygame.time.get_ticks()
        secondsLeft = timerDuration - (t - startTimerTime) // 1000
        if secondsLeft <= 0:
            secondsLeft = 0
            print("********************\n\n"
                  "Time's up\n\n"
                  f"Your score was: {score}\n\n"
                  "********************")
            pygame.quit()
            exit()

    score_text = font.render(f"Score: {score}", True, "black")
    screen.blit(score_text, (10, 10))
    lives_text = font.render(f"Lives: {lives}", True, "black")
    screen.blit(lives_text, (WIDTH - 100, 10))
    timer_text = font.render(f"Timer: {secondsLeft}", True, "black")
    screen.blit(timer_text, (WIDTH / 2 - 65, 10))

    pygame.display.update()
    clock.tick(60)
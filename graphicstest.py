from tkinter import *
from graphics import *

def main():
    win = GraphWin("lekker_pongen", 128, 96)
    balleke = Circle(Point(48,48), 2)
    paddlelinks = Rectangle(Point(1,95), Point(4,7))
    paddlerechts = Rectangle(Point(124, 25), Point(127,45))
    paddlelinks.draw(win)
    paddlerechts.draw(win)
    balleke.draw(win)
    win.getMouse() # Pause to view result
    win.close()    # Close window when done


main()
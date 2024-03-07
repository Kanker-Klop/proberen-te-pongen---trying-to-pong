from tkinter import *
import graphics

scorelinks = 0
scorerechts = 0
paddlepositielinks = 32768
paddlepositierechts = 32768
balhoek = 0
balxpos = 0
balypos = 0
balrichting = 1
balsnelheid = 4
linkerkant = -64
rechterkant = 64
bovenkant = 48
onderkant = -48

def balreset():
    global balxpos, balypos, balrichting, balhoek, scorelinks, scorerechts
    balxpos = 0
    balypos = 48
    balrichting = -1
    balhoek = 225
    print(scorelinks, scorerechts)

def balresetlinks():
    global balxpos, balypos, balrichting, scorelinks, scorerechts
    balxpos = 0
    balypos = 48
    balrichting = -1
    print(scorelinks, scorerechts)

def balresetrechts():
    global balxpos, balypos, balrichting, scorelinks, scorerechts
    balxpos = 0
    balypos = 48
    balrichting = 1
    print(scorelinks, scorerechts)

def col_me_bovenkant():
    global balhoek
    if balypos == 48 and balrichting == -1:
        balhoek = 225
    elif balypos == 48 and balrichting == 1:
        balhoek = 315

def col_me_onderkant():
    global balhoek
    if balypos == -48 and balrichting == -1:
        balhoek = 135
    elif balypos == -48 and balrichting == 1:
        balhoek = 45

def col_me_linker_of_rechtermuur():
    global balxpos, scorelinks, scorerechts
    if balxpos == linkerkant-balsnelheid:
        scorerechts += 1
        balresetrechts()
    elif balxpos == rechterkant+balsnelheid:
        scorelinks += 1
        balresetlinks()

def balbeweging():
    global balxpos, balypos, balrichting, balhoek
    if balrichting == 1 and balhoek == 45:
        print(balhoek)
        print(balxpos)
        print(balypos)
        print(balrichting)
        print()
        balxpos += balsnelheid
        balypos += balsnelheid
    elif balrichting == 1 and balhoek == 315:
        print(balhoek)
        print(balxpos)
        print(balypos)
        print(balrichting)
        print()
        balxpos += balsnelheid
        balypos -= balsnelheid
    elif balrichting == -1 and balhoek == 135:
        print(balhoek)
        print(balxpos)
        print(balypos)
        print(balrichting)
        print()
        balxpos -= balsnelheid
        balypos += balsnelheid

    elif balrichting == -1 and balhoek == 225:
        print(balhoek)
        print(balxpos)
        print(balypos)
        print(balrichting)
        print()
        balxpos -= balsnelheid
        balypos -= balsnelheid
testbeweging = 1
balreset()
while testbeweging < 54:
    col_me_bovenkant()
    col_me_onderkant()
    col_me_linker_of_rechtermuur()
    balbeweging()
    testbeweging += 1
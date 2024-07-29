import kociemba

'''
white = U 
blue = L 
orange = F 
green = R 
red = B 
yellow = D
'''

#Variables + Functions
max_steps = 50

def turn_motor(move):
    print(f"Turning motor for move: {move}")

#Cube stuff
topSide = 'UUUUUUUUU'
rightSide ='FBFRRRRRR'
frontSide = 'LRLFFFFFF'
bottomSide = 'DDDDDDDDD'
leftSide = 'BFBLLLLLL'
backSide ='RLRBBBBBB'
cube = topSide + rightSide + frontSide + bottomSide + leftSide + backSide

print(cube)

solution = kociemba.solve(cube)

steps = solution.split(" ")

for step in steps:
    match step:
        case 'U':
            turn_motor('U')
        case 'U2':
            turn_motor('U2')
        case 'U\'':
            turn_motor('U\'')
        case 'D':
            turn_motor('D')
        case 'D2':
            turn_motor('D2')
        case 'D\'':
            turn_motor('D\'')
        case 'L':
            turn_motor('L')
        case 'L2':
            turn_motor('L2')
        case 'L\'':
            turn_motor('L\'')
        case 'R':
            turn_motor('R')
        case 'R2':
            turn_motor('R2')
        case 'R\'':
            turn_motor('R\'')
        case 'F':
            turn_motor('F')
        case 'F2':
            turn_motor('F2')
        case 'F\'':
            turn_motor('F\'')
        case 'B':
            turn_motor('B')
        case 'B2':
            turn_motor('B2')
        case 'B\'':
            turn_motor('B\'')
        case _:
            print(f"Unknown move type: {step}")



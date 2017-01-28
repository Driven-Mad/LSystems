# asecgitech201617-Driven-Mad
#Description
This project is mainly about the parser, and interperting the strings. So far the L-system successfully re-writes the string based on rules perfectly.

Current Issue is interpertation: Branching off is causing an issue. Unable to resolve currently. 

#Instructions
I = Increase Generation
K = Decrease Generation
P = Print out the L-System to terminal
; = Write out the L-System to default files. 
4 = Kock Snowflake
5 = Kock curve
6 = Pleasent Error
7 = Box
8 = Box Fractal
9 = Rings


#Examples
Some L-System examples to input to the files:

Kock Snowflake:
Axiom = F--F--F
Rule = F=F+F--F+F
Angle = 60.0000
Length = 0.1000


Kock curve:
Axiom = -F
Rule = F=F-F+F+F-F
Angle = 90.0000
Length = 0.1000

Pleasent Error:
Axiom = F-F-F-F-F
Rule = F=F-F++F+F-F-F
Angle = 72.0000
Length = 0.1000

Box:
Axiom = F+F+F+F
Rule = F=FF+F+F+F+FF
Angle = 90.0000
Length = 0.1000

Box Fractal
Axiom = F-F-F-F
Rule = F=F-F+F+F-F
Angle = 90.0000
Length = 0.1000

Rings
Axiom = F+F+F+F
Rule = F=FF+F+F+F+F+F-F
Angle = 90.0000
Length = 0.1000

Seaweed (push on & Off not working apparently)
Axiom = F
Rule =  F=FF-[-F+F+F]+[+F-F-F]
Angle = 22.0000
Length = 0.1000

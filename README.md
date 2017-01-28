# asecgitech201617-Driven-Mad

I = Increase Generation
K = Decrease Generation
P = Print out the L-System to terminal
; = Write out the L-System to default files. 

Some L-System examples to input to the files:

Kock Snowflake:
Axiom = F--F--F
Rule = F=F-F++F-F
Angle = 60.0000
Length = 0.1000


Kock curve:
Axiom = -F
Rule = F-F+F+F-F
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

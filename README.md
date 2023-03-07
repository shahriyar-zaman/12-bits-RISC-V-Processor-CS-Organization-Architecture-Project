# 12-bits-RISC-V-Processor-CS-Organization-Architecture-Project
As a part of CSE332: Computer Organization and Architecture course, we made 12 bit RISC V processor. There are mainly two parts of this project. One is Assembler and another part is Logisim simulation. Basically we have a written program which will convert assembly language to machine code. For the simplicity to use it on the ROM, we convert the machine into hexadecimal values. Later, according to the hexadecimal values, we run different types Instructions like R-type, I-type, J-type instructions.

## Assembler:
An assembler can convert assembly file code to machine code. For this project, I have written a c++ program which will take input from a file name input.txt and convert the assembly code to machine code. For our convenient, we will generate hexadecimal values of the machine code in the output.txt file so that we can run this code into the Instruction Memory block of the logisim circuit.


## ISA (Instruction Set Architecture):
![isa01](https://user-images.githubusercontent.com/104163801/187024105-38c673ce-83f7-4a40-b1c9-79d22757bd29.PNG)
![isa02](https://user-images.githubusercontent.com/104163801/187024113-963e48ed-eaff-404f-bdb0-d864e7f1e7b2.PNG)
![isa03](https://user-images.githubusercontent.com/104163801/187024121-3aeddf51-7628-4e1f-886d-620a90ff2648.PNG)
![isa04](https://user-images.githubusercontent.com/104163801/187024129-5df0e64f-c511-4d69-9bb0-8d91b1d55a4b.PNG)


## List of Instructions:
![Control_Unit_Opcode](https://user-images.githubusercontent.com/104163801/187020596-df352c2f-0f33-4f95-acdf-d3468a58d8ad.png)


## Single Cycle Processor: Datapath (Logisim):
![datapath_single_cycle_final](https://user-images.githubusercontent.com/104163801/187021051-e8f0c40f-6830-4371-857a-3c811879d2fe.PNG)


## Project's Slide:
[Project Topic_ Design a 12-bit Custom RISC-Microprocessor Project Members_ Md. Samin Israk 2021362642 Shahriyar Zaman Ridoy 2022299642 Jannat Sultana 2022217642 Zinnat Fowzia Ria 1931343042.pdf](https://github.com/shahriyar-zaman/12-bit-RISC-V-Processor-CS-Organization-Architecture-Project/files/9437634/Project.Topic_.Design.a.12-bit.Custom.RISC-Microprocessor.Project.Members_.Md.Samin.Israk.2021362642.Shahriyar.Zaman.Ridoy.2022299642.Jannat.Sultana.2022217642.Zinnat.Fowzia.Ria.1931343042.pdf)

## Youtube's Presentation Link:
https://www.youtube.com/watch?v=N6HuLgdxQAo&t=236s



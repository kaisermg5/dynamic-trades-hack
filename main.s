        .gba
        .thumb
        .open "BPEE0.gba","build/rom.gba", 0x08000000
        
        .org 0x08f00000
        .importobj "build/linked.o"
        .close

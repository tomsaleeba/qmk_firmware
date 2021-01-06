# Doesn't work
- switching to the mouse layer. The ASETNIOP switch works, but not the mouse

# FIXME
- the parser.py from DennyTom creates an emtpy strings[], that breaks
    compilation. Deleting both mentions of it fixes the problem. Need to patch
    logic of `parser.py`.
- doco says up to 64 keys are supported but when I add in D and E row keys, I
    get compilation errors. I don't need all the keys so if I can ignore row C
    and some of D and E, I might be ok

# TODO
- move ASEN keys to use home row and thumb keys
- add arrow layer to ASEN

#How to build

`make`

#How to use

1. (Optional) Generate ATD definitions from inference rule declarations(Coq)

`./coqtoatd <input(Coq)> map.txt <output(.atd file)>`

example : 

input.coq (given in the first argument) :

```
  | zext_sext (src:ValueT.t) (mid:ValueT.t) (dst:ValueT.t) (srcty:typ) (midty:typ) (dstty:typ)
  | zext_zext (src:ValueT.t) (mid:ValueT.t) (dst:ValueT.t) (srcty:typ) (midty:typ) (dstty:typ)
```

output.atd :

```
type zext_sext = {
    src : value;
    mid : value;
    dst : value;
    srcty : value_type;
    midty : value_type;
    dstty : value_type;
}

type zext_zext = {
    src : value;
    mid : value;
    dst : value;
    srcty : value_type;
    midty : value_type;
    dstty : value_type;
}
```

2. Generate OCAML (inference rule-converting) codes from ATD definitions

`./atdparamconv <input(atd file)> <output(ocaml file)>`

3. Generate C++ class definitions/declarations from ATD definitions

`./atdtocpp <input(atd file)> <output(cpp file)> <output(h file)>`

`./atdtocpp <input(atd file)> <output(cpp file)> <output(h file)> <input(.txt class file list>`



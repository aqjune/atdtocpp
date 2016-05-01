  | CoreHint_t.AddAssociative (args:CoreHint_t.add_associative) -> 
     let x = Convert.register args.x in
     let y = Convert.register args.y in
     let z = Convert.register args.z in
     let c1 = Convert.const_int args.c1 in
     let c2 = Convert.const_int args.c2 in
     let c3 = Convert.const_int args.c3 in
     let sz = Convert.size args.sz in
     Infrule.Coq_add_associative (x, y, z, c1, c2, c3, sz)
  | CoreHint_t.AddSub (args:CoreHint_t.add_sub) -> 
     let minusy = Convert.register args.minusy in
     let z = Convert.register args.z in
     let x = Convert.value args.x in
     let y = Convert.value args.y in
     let sz = Convert.size args.sz in
     Infrule.Coq_add_sub (minusy, z, x, y, sz)
  | CoreHint_t.AddCommutative (args:CoreHint_t.add_commutative) -> 
     let z = Convert.register args.z in
     let x = Convert.value args.x in
     let y = Convert.value args.y in
     let sz = Convert.size args.sz in
     Infrule.Coq_add_commutative (z, x, y, sz)
  | CoreHint_t.AddShift (args:CoreHint_t.add_shift) -> 
     let y = Convert.register args.y in
     let v = Convert.value args.v in
     let sz = Convert.size args.sz in
     Infrule.Coq_add_shift (y, v, sz)
  | CoreHint_t.AddSignbit (args:CoreHint_t.add_signbit) -> 
     let x = Convert.register args.x in
     let e1 = Convert.value args.e1 in
     let e2 = Convert.value args.e2 in
     let sz = Convert.size args.sz in
     Infrule.Coq_add_signbit (x, e1, e2, sz)
  | CoreHint_t.AddOnebit (args:CoreHint_t.add_onebit) -> 
     let z = Convert.register args.z in
     let x = Convert.value args.x in
     let y = Convert.value args.y in
     Infrule.Coq_add_onebit (z, x, y)
  | CoreHint_t.AddZextBool (args:CoreHint_t.add_zext_bool) -> 
     let x = Convert.register args.x in
     let y = Convert.register args.y in
     let b = Convert.value args.b in
     let c = Convert.const_int args.c in
     let c' = Convert.const_int args.c' in
     let sz = Convert.size args.sz in
     Infrule.Coq_add_zext_bool (x, y, b, c, c', sz)
  | CoreHint_t.AddConstNot (args:CoreHint_t.add_const_not) -> 
     let z = Convert.register args.z in
     let y = Convert.register args.y in
     Infrule.Coq_add_const_not (z, y)
  | CoreHint_t.AddMask (args:CoreHint_t.add_mask) -> 
     let z = Convert.register args.z in
     let y = Convert.register args.y in
     let yp = Convert.register args.yp in
     Infrule.Coq_add_mask (z, y, yp)
  | CoreHint_t.AddSelectZero (args:CoreHint_t.add_select_zero) -> 
     let z = Convert.register args.z in
     let x = Convert.register args.x in
     let y = Convert.register args.y in
     Infrule.Coq_add_select_zero (z, x, y)
  | CoreHint_t.AddSelectZero2 (args:CoreHint_t.add_select_zero2) -> 
     let z = Convert.register args.z in
     let x = Convert.register args.x in
     let y = Convert.register args.y in
     Infrule.Coq_add_select_zero2 (z, x, y)
  | CoreHint_t.AddDistSub (args:CoreHint_t.add_dist_sub) -> 
     let z = Convert.register args.z in
     let minusx = Convert.register args.minusx in
     let minusy = Convert.register args.minusy in
     let w = Convert.register args.w in
     Infrule.Coq_add_dist_sub (z, minusx, minusy, w)
  | CoreHint_t.MulAddDistributive (args:CoreHint_t.mul_add_distributive) -> 
     let z = Convert.register args.z in
     let x = Convert.register args.x in
     let y = Convert.register args.y in
     let w = Convert.register args.w in
     Infrule.Coq_mul_add_distributive (z, x, y, w)
  | CoreHint_t.SubMone (args:CoreHint_t.sub_mone) -> 
     let z = Convert.register args.z in
     Infrule.Coq_sub_mone (z)
  | CoreHint_t.SubAdd (args:CoreHint_t.sub_add) -> 
     let z = Convert.register args.z in
     let my = Convert.value args.my in
     let x = Convert.register args.x in
     let y = Convert.value args.y in
     let sz = Convert.size args.sz in
     Infrule.Coq_sub_add (z, my, x, y, sz)
  | CoreHint_t.SubConstNot (args:CoreHint_t.sub_const_not) -> 
     let y = Convert.register args.y in
     let z = Convert.register args.z in
     Infrule.Coq_sub_const_not (y, z)
  | CoreHint_t.SubRemove (args:CoreHint_t.sub_remove) -> 
     let z = Convert.register args.z in
     let y = Convert.register args.y in
     let a = Convert.value args.a in
     let b = Convert.value args.b in
     let sz = Convert.size args.sz in
     Infrule.Coq_sub_remove (z, y, a, b, sz)
  | CoreHint_t.SubRemove2 (args:CoreHint_t.sub_remove2) -> 
     let y = Convert.register args.y in
     let z = Convert.register args.z in
     Infrule.Coq_sub_remove2 (y, z)
  | CoreHint_t.SubOnebit (args:CoreHint_t.sub_onebit) -> 
     let z = Convert.register args.z in
     Infrule.Coq_sub_onebit (z)
  | CoreHint_t.SubConstAdd (args:CoreHint_t.sub_const_add) -> 
     let y = Convert.register args.y in
     let z = Convert.register args.z in
     Infrule.Coq_sub_const_add (y, z)
  | CoreHint_t.SubSdiv (args:CoreHint_t.sub_sdiv) -> 
     let y = Convert.register args.y in
     let z = Convert.register args.z in
     Infrule.Coq_sub_sdiv (y, z)
  | CoreHint_t.SubShl (args:CoreHint_t.sub_shl) -> 
     let x = Convert.register args.x in
     let y = Convert.register args.y in
     let z = Convert.register args.z in
     Infrule.Coq_sub_shl (x, y, z)
  | CoreHint_t.MulBool (args:CoreHint_t.mul_bool) -> 
     let z = Convert.register args.z in
     let x = Convert.register args.x in
     let y = Convert.register args.y in
     Infrule.Coq_mul_bool (z, x, y)
  | CoreHint_t.MulMone (args:CoreHint_t.mul_mone) -> 
     let z = Convert.register args.z in
     Infrule.Coq_mul_mone (z)
  | CoreHint_t.MulNeg (args:CoreHint_t.mul_neg) -> 
     let z = Convert.register args.z in
     let mx = Convert.register args.mx in
     let my = Convert.register args.my in
     Infrule.Coq_mul_neg (z, mx, my)
  | CoreHint_t.MulCommutative (args:CoreHint_t.mul_commutative) -> 
     let z = Convert.register args.z in
     Infrule.Coq_mul_commutative (z)
  | CoreHint_t.MulShl (args:CoreHint_t.mul_shl) -> 
     let z = Convert.register args.z in
     let y = Convert.register args.y in
     Infrule.Coq_mul_shl (z, y)
  | CoreHint_t.DivMone (args:CoreHint_t.div_mone) -> 
     let z = Convert.register args.z in
     Infrule.Coq_div_mone (z)
  | CoreHint_t.RemNeg (args:CoreHint_t.rem_neg) -> 
     let z = Convert.register args.z in
     let my = Convert.register args.my in
     Infrule.Coq_rem_neg (z, my)
  | CoreHint_t.DivSubSrem (args:CoreHint_t.div_sub_srem) -> 
     let z = Convert.register args.z in
     let b = Convert.register args.b in
     let a = Convert.register args.a in
     Infrule.Coq_div_sub_srem (z, b, a)
  | CoreHint_t.DivSubUrem (args:CoreHint_t.div_sub_urem) -> 
     let z = Convert.register args.z in
     let b = Convert.register args.b in
     let a = Convert.register args.a in
     Infrule.Coq_div_sub_urem (z, b, a)
  | CoreHint_t.AndDeMorgan (args:CoreHint_t.and_de_morgan) -> 
     let z = Convert.register args.z in
     let x = Convert.register args.x in
     let y = Convert.register args.y in
     let z2 = Convert.register args.z2 in
     Infrule.Coq_and_de_morgan (z, x, y, z2)
  | CoreHint_t.NegVal (args:CoreHint_t.neg_val) -> 
     let c1 = Convert.const_int args.c1 in
     let c2 = Convert.const_int args.c2 in
     let sz = Convert.size args.sz in
     Infrule.Coq_neg_val (c1, c2, sz)

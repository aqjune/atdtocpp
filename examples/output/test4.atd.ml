  | CoreHint_t.AddAssociative (args:CoreHint_t.add_associative) -> 
     let x = Convert.register args.x in
     let y = Convert.register args.y in
     let z = Convert.register args.z in
     let c1 = Convert.const_int args.c1 in
     let c2 = Convert.const_int args.c2 in
     let c3 = Convert.const_int args.c3 in
     let sz = Convert.size args.sz in
     Infrule.Coq_add_associative (x, y, z, c1, c2, c3, sz)
  | CoreHint_t.TransitivityPointersLhs (args:CoreHint_t.transitivity_pointer_lhs) -> 
     let p = Convert.value args.p in
     let q = Convert.value args.q in
     let v = Convert.value args.v in
     let loadq = Convert.expr args.loadq in
     Infrule.Coq_transitivity_pointer_lhs (p, q, v, loadq)

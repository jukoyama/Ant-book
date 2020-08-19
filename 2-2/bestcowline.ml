let n = 6
let s = "ACDBCB"

let lst1 = Array.to_list (Array.init (String.length s) (String.get s))
let lst2 = List.rev lst1

let a = ref 0
let b = ref (n-1)

let rs = ref (Bytes.create n)

let rec f l1 l2 x y =
  if x >= y then true
  else match (l1, l2) with
    | ([], _) -> false
    | (_, []) -> false
    | (f1 :: r1, f2 :: r2) ->
      if (f1 < f2) then true
      else if (f1 > f2) then false
      else f r1 r2 (x+1) (y-1)

let rec solve i l1 l2 =
  if (!a > !b) then !rs
  else if i >= n then !rs
  else 
    if (f l1 l2 !a !b) then
      (a := !a + 1; Bytes.set !rs i (List.hd l1); solve (i+1) (List.tl l1) l2)
    else
      (b := !b - 1; Bytes.set !rs i (List.hd l2); solve (i+1) l1 (List.tl l2))
    
let res = solve 0 lst1 lst2

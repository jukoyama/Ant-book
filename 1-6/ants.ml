let l = 10

let n = 3

let x = [2; 6; 7]

let solve =
  let p = List.fold_left ( fun t a -> max t (min a (l-a)) ) 0 x in
  let q = List.fold_left ( fun t a -> max t (max a (l-a)) ) 0 x in
  (p, q)

let ans = solve

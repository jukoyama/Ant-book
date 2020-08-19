let n = 3

let m = 10

let k = [1; 3; 5]

(* k[c] + k[d] の取りうる値を格納したリストを返す *)
let rec f l c d =
  if c >= n then l
  else if d >= n then f l (c+1) 0
  else (List.nth k c + List.nth k d) :: f l c (d+1)

(* lst の中に、m-k[a]-k[b] を満たす値が存在するか探す *)
let rec g a b =
  let lst = f [] 0 0 in
  if a >= n then false
  else if b >= n then g (a+1) 0
  else if ( List.mem (m - List.nth k a - List.nth k b) lst ) then
    true
  else g a (b+1)

let ans = g 0 0

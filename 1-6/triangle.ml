let n = 4
let a = [4; 5; 10; 20]

let rec solve ml i j k =
  if i >= n then ml
  else if j >= n then solve ml (i+1) (i+2) (i+3)
  else if k >= n then solve ml i (j+1) (j+2)
  else 
  let x = List.nth a i in
  let y = List.nth a j in
  let z = List.nth a k in
  
  let len = x + y + z in
  let max_len  = max x (max y z) in
  let rest_len = len - max_len in

  if ( max_len < rest_len ) then solve (max ml len) i j (k+1)
  else solve ml i j (k+1)

let ans = solve 0 0 1 2

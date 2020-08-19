let n = 4

let a = [1; 2; 4; 7]

let k = 15

let rec solve i sum =
  if i = n then (sum == k)
  else if ( solve (i+1) sum ) then true
  else if ( solve (i+1) (sum + (List.nth a i)) ) then true
  else false

let ans = solve 0 0

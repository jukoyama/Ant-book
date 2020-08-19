let n = 6
let r = 10
let l = [1; 7; 15; 20; 30; 50]

let s = ref 0

let rec f lst x = match lst with
  | [] -> (x, [])
  | first :: rest ->
    if first > !s+r then (x, lst)
    else f rest first 

let rec g lst = match lst with
  | [] -> (0, [])
  | first :: rest ->
    if first > !s+r then (first, lst)
    else g rest 

let rec solve lst ans = match lst with
  | [] -> ans
  | first :: rest ->
    (s := first;
     let (p, r1) = f rest first in
     s := p; let (p', r2) = g r1 in
     s := p'; solve r2 (ans+1))
 
let res = solve l 0    

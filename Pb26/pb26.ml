module PI =
struct
	type t = int * int
	let compare = compare
end

module LOL = Set.Make(PI)

let rec cnt_bit = function
	| 0 -> 0
	| n -> (n mod 2) + cnt_bit (n/2)

let wall (x,y) =
	(cnt_bit ((x*x) + (3*x) + (2*x*y) + y + (y*y) + 1362)) mod 2 = 1

let next (a,b) =
	let lo = List.filter (fun (x,y) -> x >= 0 && y >= 0 && not (wall (x,y)))
		[a-1,b;a+1,b;a,b-1;a,b+1]
	in lo

let rec solve sc dyn next_gen = function
	| [] when sc = 50 -> LOL.cardinal dyn
	| x::l -> if LOL.mem x dyn
			  then solve sc dyn next_gen l
			  else solve sc (LOL.add x dyn) ((next x) @ next_gen) l
	| [] -> solve (sc + 1) dyn [] next_gen

let _ =
	print_int @@ solve 0 LOL.empty [] [1,1]
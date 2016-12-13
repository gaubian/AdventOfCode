type position = int * int array

module Position =
struct
   type t = position
   let compare = Pervasives.compare
end

module PSet = Set.Make(Position)

let is_ok (pos,floors) =
   let flag = ref (pos >= 0 && pos < 4) in
      for i = 0 to 4 do
         if floors.(2*i+1) <> floors.(2*i)
         then for j = 0 to 4 do
                 flag := !flag && floors.(2*j+1) <> floors.(2*i)
              done
      done;
      !flag

let next (pos,floors) l =
   let ans = ref l in
      for i = 0 to 9 do
         if floors.(i) = pos
         then for j = i to 9 do
                 if floors.(j) = pos
                 then begin
                        let up = Array.copy floors in
                        let low = Array.copy floors in
                           up.(i) <- floors.(i) + 1;
                           up.(j) <- floors.(j) + 1;
                           low.(i) <- floors.(i) - 1;
                           low.(j) <- floors.(j) - 1;
                           ans := (pos+1,up)::(pos-1,low)::!ans
                      end
              done
      done;
      !ans

let rec solve sc dyn next_gen = function
   | (_,x)::_ when Array.fold_left min 3 x = 3 -> sc 
   | x::l -> if (not (is_ok x)) || PSet.mem x dyn
             then solve sc dyn next_gen l
             else solve sc (PSet.add x dyn) (next x next_gen) l
   | [] -> (Printf.printf "sc: %d%!\n" sc; solve (sc+1) dyn [] next_gen)

let _ =
   print_int @@ solve 0 PSet.empty [] [0,[|0;0;2;1;2;1;2;1;2;1|]]
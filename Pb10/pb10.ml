 let md5 str n =
	let code = Digest.(to_hex (string (str ^ (string_of_int n)))) in
		if List.map (String.get code) [0;1;2;3;4] = ['0';'0';'0';'0';'0']
		then Some (code.[5],code.[6])
		else None

let iterate str =
	let i = ref 0 and n = ref 0 and w = "XXXXXXXX" in
		Printf.printf "%s%!\n" w;
		while !n < 8 do
			incr i;
			match md5 str !i with
				| Some (a,b) when a >= '0' && a < '8' ->
					if w.[int_of_char a - 48] = 'X'
					then (incr n;
						  w.[int_of_char a - 48] <- b;
						  Printf.printf "%s%!\n" w)
				| _ -> ()
		done

let _ = Scanf.scanf "%s" iterate
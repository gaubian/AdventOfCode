 let md5 str n =
	let code = Digest.(to_hex (string (str ^ (string_of_int n)))) in
		if List.map (String.get code) [0;1;2;3;4] = ['0';'0';'0';'0';'0']
		then Some code.[5]
		else None

let iterate str =
	let l = ref [] and i = ref 0 in
		while List.length !l < 8 do
			incr i;
			match md5 str !i with
				| Some a -> (Printf.printf "LOL%!\n"; l := a :: !l)
				| None -> ()
		done;
		List.(iter print_char (rev !l))

let _ = Scanf.scanf "%s" iterate
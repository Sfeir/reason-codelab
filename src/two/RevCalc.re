open Belt;

type entry =
  | Op(string)
  | Num(float);

let parse = tokens =>
  tokens->List.map(token =>
    try (float_of_string(token)->Num) {
    | Failure(_) => Op(token)
    }
  );

let revCalc = input => {
  let rec aux = (inp, stk) =>
    switch (inp, stk) {
    | ([Num(n), ...inpT], stk) => aux(inpT, [Num(n), ...stk])
    | ([Op("+"), ...inpT], [Num(a), Num(b), ...stkT]) =>
      aux(inpT, [Num(a +. b), ...stkT])
    | ([Op("x"), ...inpT], [Num(a), Num(b), ...stkT]) =>
      aux(inpT, [Num(a *. b), ...stkT])
    | ([], [Num(n)]) => Result.Ok(n)
    | _ => Result.Error("Malformed input")
    };
  aux(input, []);
};

let result =
  Node.Process.argv->Array.sliceToEnd(2)->List.fromArray->parse->revCalc;
Js.log(
  switch (result) {
  | Result.Ok(n) => string_of_float(n)
  | Result.Error(m) => m
  },
);
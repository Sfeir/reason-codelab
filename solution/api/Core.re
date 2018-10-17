open Belt;
open Express;
open Express.Response;

let tryDecode = (decode, req) =>
  try (decode(Request.json(req))->Result.Ok) {
  | Json.Decode.DecodeError(err) => Result.Error(err)
  };

let sayHelloWorld = (_, res, _) => sendText(res, "Hello World!");

let factorial = (req, res, _) => {
  let decode = Json.Decode.(field("n", int))->tryDecode;
  let encode = n => Json.Encode.(object_([("answer", int(n))]));

  let response = Result.(decode(req)->map(Operation.fact)->map(encode));

  switch (response) {
  | Ok(r) => sendJson(res, r)
  | Error(_) => sendStatus(res, 400)
  };
};
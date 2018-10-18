open Belt;
open Express;
open Express.Response;

type responseFormat =
  | Text(string)
  | Json(Js.Json.t);

let tryParseParam = (key, decoder, req) => {
  let params = Request.params(req);
  try (params->Js.Dict.unsafeGet(key)->decoder->Result.Ok) {
  | Failure(err) => Result.Error(err)
  };
};

let tryDecodeJson = (decoder, req) =>
  try (decoder(Request.json(req))->Result.Ok) {
  | Json.Decode.DecodeError(err) => Result.Error(err)
  };

let makeHandler = (decode, calc, encode, req, res) => {
  let response = Result.(decode(req)->map(calc)->map(encode));
  switch (response) {
  | Ok(Text(s)) => sendText(res, s)
  | Ok(Json(j)) => sendJson(res, j)
  | Error(err) => res->status(400)->sendText(err)
  };
};

let sayHelloWorld = (_, res) => sendText(res, "Hello World!");

let volume = {
  let decode = tryParseParam("rad", float_of_string);
  let encode = vol => string_of_float(vol)->Text;
  makeHandler(decode, Operation.volume, encode);
};

let factorial = {
  let decode = tryDecodeJson(Json.Decode.(field("n", int)));
  let encode = n => Json.Encode.(object_([("answer", int(n))]))->Json;
  makeHandler(decode, Operation.fact, encode);
};
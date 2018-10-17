module Request = {
  type t;
};

module Response = {
  type t;

  [@bs.send] external send: (t, string) => unit = "";
};

type middleware = (Request.t, Response.t, unit => unit) => unit;

module App = {
  type t;

  [@bs.send] external get: (t, string, middleware) => t = "";
  [@bs.send] external listen: (t, int, unit => unit) => unit = "";
};

[@bs.module] external makeApp: unit => App.t = "express";
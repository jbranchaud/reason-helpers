/****************/
/* List Helpers */
/****************/

/* get the last item out of a list */
let rec last_opt = (items: list('a)): option('a) =>
  switch (items) {
  | [] => None
  | [last_item] => Some(last_item)
  | [_, ...rest] => last_opt(rest)
  };

/* swap two items in a list */
let swap = (i: int, j: int, items: list('a)): list('a) => {
  let i_item = List.nth(items, i);
  let j_item = List.nth(items, j);

  let swapper =
    List.mapi((index, item) =>
      switch (index) {
      | x when x == i => j_item
      | x when x == j => i_item
      | _ => item
      }
    );

  swapper(items);
};

type take_result = {
  take: list(string),
  remain: list(string),
};

let rec take = (items: list('a), count: int): take_result =>
  switch (items, count) {
  | ([], _) => {take: [], remain: []}
  | (remain, 0) => {take: [], remain}
  | ([first, ...rest], n) =>
    let result = take(rest, n - 1);
    {take: [first, ...result.take], remain: result.remain};
  };

/* End of List Helpers */

/******************/
/* String Helpers */
/******************/

/* get a copy of a string with the first char removed */
let remove_first_char = (str: string): string =>
  switch (String.length(str) - 1) {
  | copy_len when copy_len < 0 => ""
  | copy_len =>
    let dst = Bytes.create(copy_len);
    Bytes.blit_string(str, 1, dst, 0, copy_len);
    Bytes.to_string(dst);
  };

/* get a copy of a string with the last char removed */
let remove_last_char = (str: string): string =>
  switch (String.length(str) - 1) {
  | copy_len when copy_len < 0 => ""
  | copy_len =>
    let dst = Bytes.create(copy_len);
    Bytes.blit_string(str, 0, dst, 0, copy_len);
    Bytes.to_string(dst);
  };

/* get the list of chars that make up a string */
let string_to_chars = (string): list(char) =>
  String.to_seq(string) |> List.of_seq;

/* compute the Levenshtein distance between two strings */
let rec lev_distance = (s1: string, s2: string): int =>
  switch (String.length(s1), String.length(s2)) {
  | (0, s1_length) => s1_length
  | (s2_length, 0) => s2_length
  | (s1_length, s2_length) =>
    let cost = s1.[s1_length - 1] == s2.[s2_length - 1] ? 0 : 1;
    let d1 = lev_distance(remove_last_char(s1), s2) + 1;
    let d2 = lev_distance(s1, remove_last_char(s2)) + 1;
    let d3 =
      lev_distance(remove_last_char(s1), remove_last_char(s2)) + cost;
    min(d1, min(d2, d3));
  };

/* End of String Helpers */

/****************/
/* File Helpers */
/****************/

/* get all the lines from an in_channel */
let rec read_lines_from_in_channel = (in_channel): list(string) =>
  switch (input_line(in_channel)) {
  | exception End_of_file => []
  | "" => read_lines_from_in_channel(in_channel)
  | line => [line, ...read_lines_from_in_channel(in_channel)]
  };

/* get all the lines from a file as a list of strings */
let read_lines_from_file = (filename: string): list(string) => {
  let in_channel = Pervasives.open_in(filename);

  let strings = read_lines_from_in_channel(in_channel);

  Pervasives.close_in(in_channel);

  strings;
};

/* End of File Helpers */

/**********************/
/* Functional Helpers */
/**********************/

/* flip the two arguments that get passed to a function */
let flip = (f, a, b) => f(b, a);

/* add two int values */
let add = (a: int, b: int): int => a + b;

/* fold_left helper for summing a list of ints */
let sum = (l: list(int)): int => List.fold_left(add, 0, l);

/* End of Functional Helpers */

/**********************/
/*** Option Helpers ***/
/**********************/

/* attribution: Sean Grove (https://gist.github.com/sgrove/600eeb97a70b4cd6c9b54041281ee503) */
let default = (value, opt) =>
  switch (opt) {
  | None => value
  | Some(value) => value
  };

/* attribution: Sean Grove (https://gist.github.com/sgrove/600eeb97a70b4cd6c9b54041281ee503) */
let expect = (name, opt) =>
  switch (opt) {
  | None => raise(Failure("Missing value for " ++ name))
  | Some(value) => value
  };

/* attribution: Sean Grove (https://gist.github.com/sgrove/600eeb97a70b4cd6c9b54041281ee503) */
let map = (opt, update) =>
  switch (opt) {
  | None => None
  | Some(value) => Some(update(value))
  };

/* attribution: Sean Grove (https://gist.github.com/sgrove/600eeb97a70b4cd6c9b54041281ee503) */
let fmap = (opt, update) =>
  switch (opt) {
  | None => None
  | Some(value) => update(value)
  };

let exists = (opt: option('a)): bool =>
  switch (opt) {
  | None => false
  | Some(_) => true
  };

/*** End of Option Helpers ***/
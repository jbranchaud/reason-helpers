/* get the last item out of a list */
let rec last_opt = (items: list('a)): option('a) =>
  switch (items) {
  | [] => None
  | [last_item] => Some(last_item)
  | [_, ...rest] => last_opt(rest)
  };

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

/* flip the two arguments that get passed to a function */
let flip = (f, a, b) => f(b, a);
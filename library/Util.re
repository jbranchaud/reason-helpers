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
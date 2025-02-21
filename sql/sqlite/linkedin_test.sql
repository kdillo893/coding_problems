-- creating tables and inserting values for the question that showed in suggested stuff


CREATE TABLE IF NOT EXISTS Customers (
  customer_id long unique not null,
  first_name varchar(80),
  last_name varchar(80)
);

CREATE TABLE IF NOT EXISTS Orders (
  order_id long unique not null,
  item varchar(80),
  amount varchar(80),
  customer_id long,
  FOREIGN KEY(customer_id) REFERENCES Customers(customer_id)
);

CREATE TABLE IF NOT EXISTS Shippings (
  shipping_id long unique not null,
  status int not null,
  customer_id long,
  FOREIGN KEY(customer_id) REFERENCES Customers(customer_id)
);


INSERT INTO Customers (
  customer_id, first_name, last_name
) VALUES
( 3, 'Kevin', 'Dillon' ),
( 4, 'John', 'Snow' ),
( 5, 'Geoffree', 'Dumber');

INSERT INTO Orders (
  order_id,item,amount,customer_id
) VALUES
(1, 'Keyboard', 400, 4),
(2, 'Mouse', 300, 4),
(3, 'Monitor', 1200, 3),
(4, 'Keyboard', 400, 1),
(5, 'Mousepad', 30, 2);

INSERT INTO Shippings (
  shipping_id,status,customer_id
) VALUES
(1, 1, 2),
(2, 0, 2),
(3, 1, 2),
(4, 0, 2),
(5, 1, 2);

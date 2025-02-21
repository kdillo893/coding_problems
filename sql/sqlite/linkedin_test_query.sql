-- The idea was to join and get "clearance rate" of orders.
-- the wrong query is something like this with counts weighted

SELECT DISTINCT c.customer_id, o.*
FROM Customers c
  FULL OUTER JOIN Orders o ON c.customer_id = o.customer_id;

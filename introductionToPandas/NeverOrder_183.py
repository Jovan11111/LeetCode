import pandas as pd

def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    customers = customers[~customers["id"].isin(orders["customerId"])][["name"]]
    return customers.rename(columns = {"name": "Customers"})
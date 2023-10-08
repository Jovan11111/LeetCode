import pandas as pd


def findHeavyAnimals(animals: pd.DataFrame) -> pd.DataFrame:
    animals = animals[animals["weight"] > 100]
    animals = animals.sort_values(by="weight", ascending=False)
    animals = animals[['name']].reset_index(drop=True)

    return animals
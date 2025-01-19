import uvicorn
from fastapi import FastAPI

app = FastAPI()


@app.get("/")
def read_root():
    return {"message": "Welcome to FastAPI!"}


@app.get("/items/{item_id}")
def read_item(item_id: int, q: str = None):
    return {"item_id": item_id, "query": q}


@app.post('/item/{main}')
def read_post_item(main:int,allporducts:bool):
    temp = main.bit_count()
    return {
        main:"temper singh",
        itemsCount:main,
        items:allporducts
    }

if __name__ == "__main__":
    uvicorn.run(app, port=8000)

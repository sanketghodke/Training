import { useState, useEffect } from "react"
import axios from 'axios';

const url='https://qghcujpqbvrdfszremfe.supabase.co/rest/v1/blogs'
const CreateBlog = () => {

    const [data, setData] = useState({
        title:"",
        description:"",
        author:"",
        reading_time:""
    })


    function handleSubmit(e){
        e.preventDefault();
        const newData={...data}
        console.log("Newdata ",newData)

        //Send payload in a key value pair
        const payload={
        title:newData.title[0],
        description:newData.description[0],
        author:newData.author[0],
        reading_time:newData.reading_time[0]
}
console.log("Payload ",payload)
        axios.post(url,payload,{
            headers: {
                'Authorization': 'Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6InFnaGN1anBxYnZyZGZzenJlbWZlIiwicm9sZSI6ImFub24iLCJpYXQiOjE2NTgxMjk3NzcsImV4cCI6MTk3MzcwNTc3N30.LvOp9lASnuJAAwvg2VxFmnrVXuqZOM0KVngw8EKHQcM',
                'apikey': 'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6InFnaGN1anBxYnZyZGZzenJlbWZlIiwicm9sZSI6ImFub24iLCJpYXQiOjE2NTgxMjk3NzcsImV4cCI6MTk3MzcwNTc3N30.LvOp9lASnuJAAwvg2VxFmnrVXuqZOM0KVngw8EKHQcM'
            }
        }).then(res=>{
            console.log(res.data)
        })


    }

    function handleChange(e){
        const newData={...data}
        newData[e.target.id]=[e.target.value]
        setData(newData)

    }
    return(

       <>
       <div className="container">
       <div className="text-start">
       
            <form onSubmit={(e)=>handleSubmit(e)}>
                <div className="mb-3">
                        <label for="exampleFormControlTextarea1" className="form-label">Title</label>
                        <textarea className="form-control" id="title" rows="1" onChange={(e)=>handleChange(e)} value={data.title}></textarea>
                </div>    
                <div className="mb-3">
                    <label for="exampleFormControlTextarea1" className="form-label">Description</label>
                    <textarea className="form-control" id="description" rows="2" onChange={(e)=>handleChange(e)} value={data.description} ></textarea>
                </div>
                <div className="mb-3">
                    <label for="exampleFormControlTextarea1" className="form-label">Author</label>
                    <textarea className="form-control" id="author" rows="1" onChange={(e)=>handleChange(e)} value={data.author} ></textarea>
                </div>
                <div className="mb-3">
                    <label for="exampleFormControlTextarea1" className="form-label">Reading Time</label>
                    <textarea className="form-control" id="reading_time" rows="1" onChange={(e)=>handleChange(e)} value={data.reading_time} ></textarea>
                </div>
                <input type="submit" value="Submit" />
                <br/>

            </form>
        </div>
        </div>
       </>
    )


   


}

export default CreateBlog

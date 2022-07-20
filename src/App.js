import './App.css';
import React, { Component } from 'react';
import { BrowserRouter as Router, Route, Link } from 'react-router-dom';            
import Blogs from './components/Blogs'
import CreateBlog from'./components/CreateBlog'
function App() {
  return (
    <div className="App">
    
    
      <CreateBlog/>
      <br/>
      <Blogs/>

     
    </div>
    
    
  );
}

export default App;

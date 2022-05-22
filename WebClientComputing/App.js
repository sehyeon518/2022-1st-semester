import React from 'react';
import NewsList from './components2/NewsList';
import Categories from './components2/Categories';
import Summary from './components2/Summary';

const App = () => {
  return (
  <>
    <Categories />
    <Summary />
    <NewsList />
  </>
  );
};

export default App;
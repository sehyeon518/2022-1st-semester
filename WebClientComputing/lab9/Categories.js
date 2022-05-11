import React, {useState} from 'react';
import styled, { css } from 'styled-components';
import Button from '../ui/Button';
import TextArea from '../ui/TextArea';
import Text from '../ui/Text';
import Select, {Option} from '../ui/Select';
import Radio from '../ui/Radio';
import Input from '../ui/Input';
import InlineList from '../ui/InlineList'

const categories = [
  {
    name: 'all',
    text: '전체보기',
  },
  {
    name: 'business',
    text: '비즈니스',
  },
  {
    name: 'entertainment',
    text: '엔터테인먼트',
  },
  {
    name: 'health',
    text: '건강',
  },
  {
    name: 'science',
    text: '과학',
  },
  {
    name: 'sports',
    text: '스포츠',
  },
  {
    name: 'technology',
    text: '기술',
  },
];

const CategoriesBlock = styled.div`
  display: flex;
  padding: 1rem;
  width: 768px;
  margin: 0 auto;
  @media screen and (max-width: 768px) {
    width: 100%;
    overflow-x: auto;
  }
`;

const Category = styled.div`
  font-size: 1.125rem;
  cursor: pointer;
  white-space: pre;
  text-decoration: none;
  color: inherit;
  padding-bottom: 0.25rem;

  &:hover {
    color: #495057;
  }

  ${props =>
    props.active && css`
    font-weight: 600;
    border-bottom: 2px solid #22b8cf;
    color: #22b8cf;
    &:hover {
      color: #3bc9db;
    }
  `}

  & + & {
    margin-left: 1rem;
  }
`;

const Categories = ({ onSelect, state }) => {
  const [searchState, setSearchState] = useState({category:'all', country:'kr', topic:''});
  const onChange = (name, value) =>
    setSearchState({...searchState, [name]: value});
  return (
    <><CategoriesBlock>
      {categories.map(c => (
        <Category
          key={c.name}
          active={state.category === c.name}
          onClick={() => onSelect({...state, category:c.name, country:'kr', topic:''})}
        >
          {c.text}
        </Category>
      ))}
      <Button onPress={()=>onSelect({...state, show:!state.show})} primary>상세 검색</Button>
    </CategoriesBlock>
    {state.show &&
    <InlineList spacingBetween={2} verticalAlign="bottom" align="center">
      <Text xlarge bold>검색</Text>
        <Select label="카테고리" name="category" onChange={onChange}>
          <Option label="전체보기" value="" />
          <Option label="비즈니스" value="business"/>
          <Option label="엔터테인먼트" value="entertainment"/>
          <Option label="건강" value="health"/>
          <Option label="과학" value="science"/>
          <Option label="스포츠" value="sports"/>
          <Option label="기술" value="technology"/>
        </Select>
        <Radio name="country" label="한국" value="kr" cur={searchState.country} onChange={onChange}/>
        <Radio name="country" label="미국" value="us" cur={searchState.country} onChange={onChange}/>
        <Input name="topic" label="키워드" value={searchState.topic} onChange={onChange}/>
        <Button type="submit" onPress={()=>onSelect({...state, ...searchState})} primary>검색</Button>
      </InlineList>
    }


</>
    
  );
};

export default Categories;

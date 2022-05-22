import React, { useState } from 'react';
import PropTypes from 'prop-types';
import InlineList from '../ui/InlineList';
import Button from '../ui/Button';
import Text from '../ui/Text';
import Radio from '../ui/Radio';
import Input from '../ui/Input';
import Form from '../ui/Form';
import Select, { Option } from '../ui/Select';

const SearchForm = ( props ) => {

  const setResult = (values) => {
                          props.onSubmit(values);
                          console.log(values);
  }
  
  return (
    <>
      <Form onSubmit={values => setResult(values)} initValues={{category:"all", country:"kr", topic:""}}>
        <Form.Consumer>
          {({ onChange, values }) => (
            <InlineList spacingBetween={2} align="center" verticalAlign="bottom">
              <Text xlarge bold>
                검색
              </Text>
              <Select name="category" label="카테고리" onChange={onChange} value={values['category']}>
                <Option label="전체보기" value="all" />
                <Option label="비즈니스" value="business" />
                <Option label="엔터테인먼트" value="entertainment" />
                <Option label="건강" value="health" />
                <Option label="과학" value="science" />
                <Option label="스포츠" value="sports" />
                <Option label="기술" value="technology" />
              </Select>
              <Radio name="country" label="한국" value="kr" cur={values['country']} onChange={onChange} />
              <Radio name="country" label="미국" value="us" cur={values['country']} onChange={onChange} />
              <Input
                name="topic"
                label="키워드"
                onChange={onChange}
                value={values['topic']}
              />
              <Button type="submit" primary>
                검색
              </Button>
            </InlineList>
          )}
        </Form.Consumer>
      </Form>
      {/*<TextArea name={'결과'} value={JSON.stringify(state, null, 2)}/>*/}
    </>
  );
}

SearchForm.propTypes = { setFilter: PropTypes.func };

export default SearchForm;

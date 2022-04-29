import React, { useState } from 'react';
import PropTypes from 'prop-types';
import InlineList from './ui/InlineList';
import Button from './ui/Button';
import Text from './ui/Text';
import Input from './ui/Input';
import Form from './ui/Form';
import Select, { Option } from './ui/Select';
import Radio from './ui/Radio';
import CheckBox from './ui/CheckBox';
import TextArea from './ui/TextArea';

const PizzaOrderForm = ( props ) => {
    const [state, setState] = useState({});
    const setResult = (values) => { setState(values);
                                    console.log(values);
    }

    return (
        <>
        <Form onSubmit={values => setResult(values)} initValues={{pizza:"불고기 피자", quantity:1, drink:"coke"}}>
        <Form.Consumer>
            {({ onChange, values }) => (
                <InlineList spacingBetween={2} verticalAlign="bottom">
                    <Text xlarge bold>
                        피자주문
                    </Text>
                    <Select name="pizza" label="피자 종류" onChange={onChange} value={values['pizza']}>
                        <Option label="선택해주세요" value="" />
                        <Option label="불고기 피자" value="불고기" />
                        <Option label="치즈 피자" value="치즈" />
                        <Option label="도미노 피자" value="도미노" />
                    </Select>
                    <Input
                        name="quantity"
                        label="개수"
                        onChange={onChange}
                        value={values['quantity']}
                    />
                    <div>
                        <InlineList>
                            <Radio name="피자두께" label="Thick" value="Thick" cur={values.피자두께} onChange={onChange} />
                            <Radio name="피자두께" label="Medium" value="Medium" cur={values.피자두께} onChange={onChange} />
                            <Radio name="피자두께" label="Thin" value="Thin" cur={values.피자두께} onChange={onChange} />
                            <CheckBox name="양파" label="양파" checked={values.양파} onChange={onChange} />
                            <CheckBox name="페퍼로니" label="페퍼로니" checked={values.페퍼로니} onChange={onChange} />
                            <CheckBox name="미트볼" label="미트볼" checked={values.미트볼} onChange={onChange} />
                        </InlineList>
                    </div>
                    <Input
                        name="drink"
                        label="음료수"
                        onChange={onChange}
                        value={values['drink']}
                    />
                    <Button type="submit" primary>
                        주문
                    </Button>
                </InlineList>
            )}
        </Form.Consumer>
        </Form>
        <TextArea name={'결과'} value={JSON.stringify(state, null, 2)}/>
        </>
    );
}

PizzaOrderForm.propTypes = { setFilter: PropTypes.func };

export default PizzaOrderForm;
